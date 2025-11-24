#pragma once
#include <glad/glad.h>
#include <iostream>

namespace rend{
class ShaderProgram {
    public:
        ShaderProgram(const std::string& vert_sh,const std::string& frag_sh);
        ~ShaderProgram();
        bool isCompiled() const {return m_isCompiled;}
        void use() const;

        ShaderProgram() = delete;
        ShaderProgram(ShaderProgram&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;
        ShaderProgram& operator=(ShaderProgram&& ShaderProgram) noexcept;
        ShaderProgram(ShaderProgram&& ShaderProgram) noexcept;
    
    private:
        bool createShader(const std::string& source,const GLenum type,GLuint& shaderID);
        bool m_isCompiled = false;
        GLuint m_ID = 0;
};
}