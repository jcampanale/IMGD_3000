#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>
#include "Event.h"
#include "Object.h"

namespace df {

	class Manager {

	private:
		std::string type;
		bool started;

	protected:
		void setType(std::string type);

	public:
		Manager();

		std::string getType();

		virtual int StartUp();
		virtual void ShutDown();

		bool isStarted() const;

		int onEvent(const Event* p_event) const;

	};
}

#endif // __MANAGER_H__
