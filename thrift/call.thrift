/**
 * callThrift IDL
 * @author seafooler
 * @time 2016.8.15
 */

namespace go com.seafooler.project
namespace cpp com.seafooler.project

service callThrift {
	string CallFunc(1:string funcname, 2:string input);
}
