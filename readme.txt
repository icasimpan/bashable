What is bashable
 
- is yet another bash framework in an attempt to further simplify coding in bash scripting.
  This is also for personal bash scripting exercise for the author to extend further his skills on the said scripting language.


What is it capable of doing
- right now, just simple: 
   * autoloading functions
   * sql query (mysql assumed but can be changed)
  
  As the author learns, bashable will grow as well.


files
 * bin  - where the main script resides(in this case, bashable.sh)
 * conf - where config files should reside
	common_vars.cf.inc   - common files will be here (other *.cf.inc should be sourced from here)
          + db.cf.inc       - database connection information
          + logfiles.cf.inc - logfiles fullpath definitions
          + utils.cf.inc    - utils/binaries fullpath definitions
 * lib  - where functions (to be autoloaded) would reside
    + controller/bashable.bash.inc - controller for this framework
 * logs - location of log files    

functions wish list:
 - logging
 - mailer
 - function tests