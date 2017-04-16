// IFT3100H17 ~ BlinnPhongVS.glsl

#version 120

// attributs en sortie
varying vec3 interpolationPosition;
varying vec3 interpolationNormal;

void main()
{
  // transformation de la normale du sommet dans l'espace de vue
  interpolationNormal = vec3(gl_NormalMatrix * gl_Normal);

  // transformation de la position du sommet dans l'espace de vue
  interpolationPosition = vec3(gl_ModelViewMatrix * gl_Vertex);

  // transformation de la position du sommet par les matrices de modèle, vue et projection
  gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
