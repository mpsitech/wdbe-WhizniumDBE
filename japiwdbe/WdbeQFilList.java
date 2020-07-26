/**
  * \file WdbeQFilList.h
  * Java API code for record of table TblWdbeQFilList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQFilList {
	
	public WdbeQFilList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String Filename
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String osrefKContent
				, String titOsrefKContent
				, String srefKMimetype
				, String titSrefKMimetype
				, int Size
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.Filename = Filename;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.osrefKContent = osrefKContent;
		this.titOsrefKContent = titOsrefKContent;
		this.srefKMimetype = srefKMimetype;
		this.titSrefKMimetype = titSrefKMimetype;
		this.Size = Size;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String Filename;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String osrefKContent;
	public String titOsrefKContent;
	public String srefKMimetype;
	public String titSrefKMimetype;
	public int Size;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQFilList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			Filename = Xmlio.extractStringUclc(doc, basexpath, "Filename", "fnm", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			osrefKContent = Xmlio.extractStringUclc(doc, basexpath, "osrefKContent", "cnt", null, 0);
			titOsrefKContent = Xmlio.extractStringUclc(doc, basexpath, "titOsrefKContent", "cnt2", null, 0);
			srefKMimetype = Xmlio.extractStringUclc(doc, basexpath, "srefKMimetype", "mim", null, 0);
			titSrefKMimetype = Xmlio.extractStringUclc(doc, basexpath, "titSrefKMimetype", "mim2", null, 0);
			Size = Xmlio.extractIntegerUclc(doc, basexpath, "Size", "siz", null, 0);
			
			return true;
		};

		return false;
	};
};

