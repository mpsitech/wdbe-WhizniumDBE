export default {
	toBase64: function(arr) {
		return(btoa(String.fromCharCode.apply(null, new Uint8Array(arr.buffer))));
	},
	
	fromBase64: function(str) {
		var strlen, cnt, ix, outbuf, dv, outbuflen, quad, trip;
	
		strlen = str.length;
	
		outbuflen = 0;
		for (let i = strlen; i > 0; i--) {
			if ((str[i-1] == '\n') || (str[i-1] == '\r') || (str[i-1] == '\t') || (str[i-1] == ' ')) continue;
			else if (str[i-1] == '=') outbuflen--;
			else break;
		}
	
		ix = 0;
		for (let i = 0; i < strlen; i++) if ((str[i] == '\n') || (str[i] == '\r') || (str[i] == '\t') || (str[i] == ' ')) ix++;
		strlen -= ix;
	
		cnt = strlen/4;
	
		quad = new Uint8Array(4);
		trip = new Uint8Array(3);
	
		if ((strlen >= 4) && ((strlen%4) == 0)) {
			outbuflen += 3*cnt;
	
			outbuf = new ArrayBuffer(outbuflen);
			dv = new DataView(outbuf);
	
			ix = 0;
	
			for (let i = 0; i < cnt; i++) {
				while ((str[ix] == '\n') || (str[ix] == '\r') || (str[ix] == '\t') || (str[ix] == ' ')) ix++;
				quad[0] = str.charCodeAt(ix++);
				while ((str[ix] == '\n') || (str[ix] == '\r') || (str[ix] == '\t') || (str[ix] == ' ')) ix++;
				quad[1] = str.charCodeAt(ix++);
				while ((str[ix] == '\n') || (str[ix] == '\r') || (str[ix] == '\t') || (str[ix] == ' ')) ix++;
				quad[2] = str.charCodeAt(ix++);
				while ((str[ix] == '\n') || (str[ix] == '\r') || (str[ix] == '\t') || (str[ix] == ' ')) ix++;
				quad[3] = str.charCodeAt(ix++);
	
				for (let j = 0; j < 4; j++) {
					if ((quad[j] >= 0x41) && (quad[j] <= 0x5a)) quad[j] = quad[j] - 0x41;
					else if ((quad[j] >= 0x61) && (quad[j] <= 0x7a)) quad[j] = quad[j] - 0x61 + 26;
					else if ((quad[j] >= 0x30) && (quad[j] <= 0x39)) quad[j] = quad[j] - 0x30 + 52;
					else if (quad[j] == 0x2b) quad[j] = 62;
					else if (quad[j] == 0x20) quad[j] = 62; // quick fix for HTTP encoding of space as plus
					else if (quad[j] == 0x2f) quad[j] = 63;
					else if (quad[j] == 0x3d) quad[j] = 255;
					else quad[j] = 0;
				}
	
				trip[0] = 4*quad[0] + (quad[1] & 0xf0)/16;
				trip[1] = 16*(quad[1] & 0x0f) + (quad[2] & 0xfc)/4;
				trip[2] = 64*(quad[2] & 0x03) + quad[3];
	
				dv.setUint8(3*i, trip[0]);
	
				if (i == (cnt-1)) {
					if (quad[2] != 255) {
						dv.setUint8(3*i+1, trip[1]);
						if (quad[3] != 255) dv.setUint8(3*i+2, trip[2]);
					}
				} else {
					dv.setUint8(3*i+1, trip[1]);
					dv.setUint8(3*i+2, trip[2]);
				}
			}
	
			return outbuf;
		}
	
		return null;
	},
	
	bigendian: function() {
		return((new Uint8Array(new Uint32Array([0x12345678]).buffer)[0]) == 0x12);
	},
	
	invertBuffer: function(_buf, varlen) {
		var len = _buf.byteLength/varlen;
		var buf = new Uint8Array(_buf);
	
		var c;
	
		for (var i = 0; i < len; i++) {
			for (var j = 0; j < varlen/2; j++) {
				c = buf[i*varlen+j];
	
				buf[i*varlen+j] = buf[i*varlen+(varlen-j-1)];
				buf[i*varlen+(varlen-j-1)] = c;
			}
		}
	},
	
	parseUtinyintvec: function(str) {
		var buf;
		
		buf = this.fromBase64(str);
	
		if (buf) return new Uint8Array(buf);
	
		return new Uint8Array(0);
	},

	parseUintvec: function(str) {
		var varlen = 4;
	
		var buf, buflen;
		
		buf = this.fromBase64(str);
	
		if (buf) {
			buflen = buf.byteLength;
			if ((buflen%varlen) == 0) {
				if (!this.bigendian()) this.invertBuffer(buf, varlen);
	
				return new Uint32Array(buf);
			}
		}
	
		return new Uint32Array(0);
	}
}
