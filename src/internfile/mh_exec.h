/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef _MH_EXEC_H_INCLUDED_
#define _MH_EXEC_H_INCLUDED_
/* @(#$Id: mh_exec.h,v 1.6 2008-10-02 13:30:32 dockes Exp $  (C) 2004 J.F.Dockes */

#include <string>
#include <list>
using std::list;
using std::string;

#include "mimehandler.h"

/** 
 * Turn external document into internal one by executing an external filter.
 *
 * The command to execute, and its parameters, are stored in the "params" 
 * which is built in mimehandler.cpp out of data from the mimeconf file.
 */
class MimeHandlerExec : public RecollFilter {
 public:
    list<string> params;
    MimeHandlerExec(const string& mt) : RecollFilter(mt) {}
    virtual ~MimeHandlerExec() {}
    virtual bool set_document_file(const string &file_path) {
	m_fn = file_path;
	m_havedoc = true;
	return true;
    }
    virtual bool next_document();
    virtual bool skip_to_document(const string& ipath) {
	m_ipath = ipath;
	return true;
    }
private:
    string m_fn;
    string m_ipath;
};

#endif /* _MH_EXEC_H_INCLUDED_ */
