#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
namespace df {

	class Event {
	private:
		std::string type;

	public:
		Event();

		virtual ~Event();

		void setType(std::string new_type);

		std::string getType() const;
	};

}

#endif // __EVENT_H__