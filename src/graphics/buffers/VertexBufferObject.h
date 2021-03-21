#pragma once
#include <GL/glew.h>

namespace gengine {
    namespace graphics {
        class VertexBufferObject
        {
        private:
            GLuint vbo_id;
        public:
            VertexBufferObject(GLfloat* data, GLsizeiptr size, GLenum usage);
            ~VertexBufferObject();
            void bind() const;
            void unbind() const;
        };
    }
}