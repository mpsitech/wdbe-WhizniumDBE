/**
  * \file WdbeQErrAPar.h
  * Java API code for record of table TblWdbeQErrAPar
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQErrAPar {
	
	public WdbeQErrAPar(
				int jnum
				, String sref
				, String srefIxWdbeVPartype
				, String titIxWdbeVPartype
				, String stubRefWdbeMVector
				, int Length
				, String Comment
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxWdbeVPartype = srefIxWdbeVPartype;
		this.titIxWdbeVPartype = titIxWdbeVPartype;
		this.stubRefWdbeMVector = stubRefWdbeMVector;
		this.Length = Length;
		this.Comment = Comment;
	};

	public int jnum;
	public String sref;
	public String srefIxWdbeVPartype;
	public String titIxWdbeVPartype;
	public String stubRefWdbeMVector;
	public int Length;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQErrAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxWdbeVPartype = Xmlio.extractStringUclc(doc, basexpath, "srefIxWdbeVPartype", "pty", null, 0);
			titIxWdbeVPartype = Xmlio.extractStringUclc(doc, basexpath, "titIxWdbeVPartype", "pty2", null, 0);
			stubRefWdbeMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMVector", "vec", null, 0);
			Length = Xmlio.extractIntegerUclc(doc, basexpath, "Length", "len", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};

