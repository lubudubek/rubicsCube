#shader vertex
#version 330
in vec4 vp;
void main() {
  gl_Position = vp;
};

#shader fragment
#version 330
out vec4 frag_colour;

uniform vec4 u_Color;

void main() {
  frag_colour = u_Color;
};