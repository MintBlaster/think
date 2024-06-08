#version 450 core

in vec2 TexCoord;
layout(location = 0) out vec4 FragColor;

uniform sampler2D texture1;

void main() {
    vec4 texColor = texture(texture1, TexCoord);

    FragColor = texColor;
}
