uniform sampler2D texture;
uniform float wave;

void main() {
    vec2 coord = gl_TexCoord[0].xy;
    coord.y += sin(coord.x * 10.0 + wave) * 0.05;
    gl_FragColor = texture2D(texture, coord) * gl_Color;
}