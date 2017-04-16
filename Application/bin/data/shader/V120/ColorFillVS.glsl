// IFT3100H17 ~ ColorFillVS.glsl

#version 120

// couleur de remplissage du matériau
uniform vec3 color;

void main()
{
  // transformation de la position du sommet par les matrices de modèle, vue et projection
  gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
