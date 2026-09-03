void main()
{
    // Pass the standard texture coordinates (0.0 to 1.0) to the fragment shader
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // Transform vertex position using SFML's modelview/projection matrix
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}