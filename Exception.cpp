#include <exception>
#include <string>

class Exception : std::exception
{
	protected:
		std::string msg;
	public:
		explicit Exception(const std::string& message) : msg(message) {}
		virtual ~Exception() noexcept {}
		virtual const char* what() const noexcept { return this->msg.c_str(); }
};