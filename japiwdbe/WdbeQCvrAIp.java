/**
	* \file WdbeQCvrAIp.h
	* Java API code for record of table TblWdbeQCvrAIp
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCvrAIp {
	
	public WdbeQCvrAIp(
				int jnum
				, String sref
				, String srefIxVTagtype
				, String titIxVTagtype
				, String Comment
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVTagtype = srefIxVTagtype;
		this.titIxVTagtype = titIxVTagtype;
		this.Comment = Comment;
	};

	public int jnum;
	public String sref;
	public String srefIxVTagtype;
	public String titIxVTagtype;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCvrAIp");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVTagtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVTagtype", "tty", null, 0);
			titIxVTagtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVTagtype", "tty2", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};
