#shader vertex
#version 330
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

out vec4 Color;

uniform mat4 u_MVP;

void main() {
  gl_Position = u_MVP * position;
  Color = color;
};

#shader fragment
#version 330
out vec4 frag_colour;
in vec4 Color;

uniform sampler2D u_Texture;

void main()
{
    frag_colour = Color;
};