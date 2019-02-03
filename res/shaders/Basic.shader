#shader vertex
#version 330 core
#extension GL_ARB_explicit_attrib_location : enable

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textureCoord;

out vec2 v_textureCoord;
uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * position;
    v_textureCoord = textureCoord;
};

#shader fragment
#version 330 core
#extension GL_ARB_explicit_attrib_location : enable

layout(location = 0) out vec4 color;

in vec2 v_textureCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    vec4 textureColor = texture(u_Texture, v_textureCoord);
    color = textureColor;
};