/*
	By Jenocn
	https://jenocn.github.io/
*/

#include <string>

namespace GCL {
namespace Base {
class PathTool {
public:
	static std::string Join(const std::initializer_list<std::string>& paths, char separtor = '/');
	static std::string Join(const std::string& src, const std::string& dest, char separtor = '/');
	static std::string NormalizeJoin(const std::initializer_list<std::string>& paths, char separtor = '/');
	static std::string NormalizeJoin(const std::string& src, const std::string& dest, char separtor = '/');
	static std::string Normalize(const std::string& path, char separtor = '/');
	static std::string Extname(const std::string& filename);

private:
	static bool _IsSepartor(char ch);
};
} // namespace Base
} // namespace GCL