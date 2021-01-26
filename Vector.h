#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <string>

namespace df{
    class Vector{

        private:
            float x;
            float y;

        public:
            Vector(float xPos, float yPos);
            Vector();

            float getX() const;
            void setX(float newX);
            float getY() const;
            void setY(float newY);

            void normalize();
            void scale(float s);
            float getMagnitude() const;

            Vector operator+(const Vector& other) const;
    };
}

#endif // __VECTOR_H__