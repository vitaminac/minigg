#include "VertexArrayObject.h"

namespace gengine {
    namespace graphics {

        VertexArrayObject::VertexArrayObject()
        {
            // Create single VAO which contains the vertex array state
            glGenVertexArrays(1, &vao_id);
        }

        VertexArrayObject::~VertexArrayObject()
        {
            for (int i = 0; i < buffers.size(); i++)
                delete buffers[i];
            // When you are done this will destroy the VAO
            glDeleteVertexArrays(1, &vao_id);
        }

        void VertexArrayObject::bind() const
        {
            glBindVertexArray(vao_id);
        }

        void VertexArrayObject::unbind() const
        {
            glBindVertexArray(0);
        }


        void VertexArrayObject::addBuffer(VertexBufferObject* buffer, GLuint index, GLint componentCount)
        {
            this->bind();
            buffer->bind();

            // Enables the generic vertex attribute specified by index for use in drawing
            glEnableVertexAttribArray(index);

            /*
            The association between a buffer object and a vertex attribute
            happens when you call glVertexAttribPointer
            */

            /*
            When you call glVertexAttribPointer,
            OpenGL takes whatever buffer is at the moment
            of this call bound to GL_ARRAY_BUFFER
            and associates it with the given vertex attribute.
            */

            // Specify format of a VBO, put that information in the VAO
            glVertexAttribPointer(index, componentCount, GL_FLOAT, GL_FALSE, 0, 0);

            buffer->unbind();
            this->unbind();
        }
    }
}