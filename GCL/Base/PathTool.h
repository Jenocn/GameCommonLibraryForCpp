/*
	By Jenocn
	https://jenocn.github.io/
*/

#include <string>

namespace GCL {
namespace Base {
class PathTool {
public:
	static std::string Join(const std::initializer_list<std::string>& paths);
	static std::string Join(const std::string& src, const std::string& dest);
	static std::string Normalize(const std::string& path);
	static std::string Extname(const std::string& filename);
};
}
}