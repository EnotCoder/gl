#include "ShaderProgram.h"
#include <iostream>

namespace rend {
    ShaderProgram::ShaderProgram(const std::string& vert_sh, const std::string& frag_sh)
    {
        GLuint vertexShaderID;
        if (!createShader(vert_sh,GL_VERTEX_SHADER,vertexShaderID))
        {
            std::cerr << "VERTEX SHADER ERROR";
            return;
        };

        GLuint fragmentshaderID;
        if (!createShader(frag_sh,GL_FRAGMENT_SHADER,fragmentshaderID))
        {
            std::cerr << "FRAGMENT SHADER ERROR";
            glDeleteShader(vertexShaderID);
            return;
        };
        
        m_ID = glCreateProgram();
        glAttachShader(m_ID,vertexShaderID);
        glAttachShader(m_ID,fragmentshaderID);
        glLinkProgram(m_ID);

        GLint success;
        glGetProgramiv(m_ID,GL_LINK_STATUS,&success);
        if (!success)
        {
            GLchar infoLog[1024];
            glGetProgramInfoLog(m_ID,1024,nullptr,infoLog);
            std::cerr << "ERROR" << infoLog << std::endl;    
        }
        else
        {
            m_isCompiled = true;
        }

        glDeleteShader(vertexShaderID);
	    glDeleteShader(fragmentshaderID);
    }
    bool ShaderProgram::createShader(const std::string& source,const GLenum type,GLuint& shaderID)
    {
        shaderID = glCreateShader(type);
        const char* code = source.c_str();
        glShaderSource(shaderID,1,&code,nullptr);
        glCompileShader(shaderID);

        GLint success;
        glGetShaderiv(shaderID,GL_COMPILE_STATUS,&success);
        if (!success)
        {
            GLchar infoLog[1024];
            glGetShaderInfoLog(shaderID,1024,nullptr,infoLog);
            std::cerr << "ERROR" << infoLog << std::endl;    
            return false;
        }
        return true;
    }
    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(m_ID);
    }

    void ShaderProgram::use() const 
    {
        glUseProgram(m_ID);
    }

    ShaderProgram& ShaderProgram::operator=(ShaderProgram&& ShaderProgram) noexcept
    {
        glDeleteProgram(m_ID);
        m_ID = ShaderProgram.m_ID;
        m_isCompiled = ShaderProgram.isCompiled();

        ShaderProgram.m_ID = 0;
        ShaderProgram.m_isCompiled = false;
        return *this;
    }
    ShaderProgram::ShaderProgram(ShaderProgram&& ShaderProgram) noexcept
    {
        m_ID = ShaderProgram.m_ID;
        m_isCompiled = ShaderProgram.isCompiled();

        ShaderProgram.m_ID = 0;
        ShaderProgram.m_isCompiled = false;
    }
}