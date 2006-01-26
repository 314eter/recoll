#ifndef _SMALLUT_H_INCLUDED_
#define _SMALLUT_H_INCLUDED_
/* @(#$Id: smallut.h,v 1.14 2006-01-26 12:29:20 dockes Exp $  (C) 2004 J.F.Dockes */
#include <string>
#include <list>

#ifndef NO_NAMESPACES
using std::string;
using std::list;
#endif /* NO_NAMESPACES */

extern int stringicmp(const string& s1, const string& s2);
extern int stringlowercmp(const string& alreadylower, const string& s2);
extern int stringuppercmp(const string& alreadyupper, const string& s2); 

// Compare charset names, removing the more common spelling variations
extern bool samecharset(const string &cs1, const string &cs2);

extern bool maketmpdir(string& tdir);
extern string stringlistdisp(const list<string>& strs);

/**
 * Parse input string into list of strings. 
 *
 * Token delimiter is " \t" except inside dquotes. dquote inside
 * dquotes can be escaped with \ etc...
 */
extern bool stringToStrings(const string &s, list<string> &tokens);

/**
 * Split input string. No handling of quoting
 */
extern void stringToTokens(const string &s, list<string> &tokens, 
			   const string &delims = " \t");

/** Convert string to boolean */
extern bool stringToBool(const string &s);

/** Remove instances of characters belonging to set (default {space,
    tab}) at beginning and end of input string */
extern void trimstring(string &s, const char *ws = " \t");

/** Escape things like < or & by turining them to entities */
extern string escapeHtml(const string &in);


class Chrono {
 public:
  Chrono();
  /** Reset origin */
  long restart();
  /** Snapshot current time */
  static void refnow();
  /** Get current elapsed since creation or restart
   *
   *  @param frozen give time since the last refnow call (this is to
   * allow for using one actual system call to get values from many
   * chrono objects, like when examining timeouts in a queue)
   */
  long millis(int frozen = 0);
  long micros(int frozen = 0);
  float secs(int frozen = 0);
 private:
  long	m_secs;
  long 	m_nsecs; 
};


#endif /* _SMALLUT_H_INCLUDED_ */
