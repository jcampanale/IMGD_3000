#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace df{

    class Clock{

        private:
            long int previousTime;
        
        public:
            Clock();
            long int delta();
            long int split() const;
    };
}

#endif // __CLOCK_H__
