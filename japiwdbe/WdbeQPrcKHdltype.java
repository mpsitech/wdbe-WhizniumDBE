/**
	* \file WdbeQPrcKHdltype.h
	* Java API code for record of table TblWdbeQPrcKHdltype
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrcKHdltype {
	
	public WdbeQPrcKHdltype(
				int jnum
				, String yesnoFixed
				, String sref
				, String Avail
				, String Implied
				, String Title
				, String Comment
			) {
		this.jnum = jnum;
		this.yesnoFixed = yesnoFixed;
		this.sref = sref;
		this.Avail = Avail;
		this.Implied = Implied;
		this.Title = Title;
		this.Comment = Comment;
	};

	public int jnum;
	public String yesnoFixed;
	public String sref;
	public String Avail;
	public String Implied;
	public String Title;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrcKHdltype");

		if (Xmlio.checkXPath(doc, basexpath)) {
			yesnoFixed = Xmlio.extractStringUclc(doc, basexpath, "yesnoFixed", "fix", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Avail = Xmlio.extractStringUclc(doc, basexpath, "Avail", "avl", null, 0);
			Implied = Xmlio.extractStringUclc(doc, basexpath, "Implied", "imp", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};
