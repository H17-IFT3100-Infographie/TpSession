// IFT3100H17 ~ LambertVS.glsl

#version 330

// attribut de sommet
in vec4 position;
in vec4 normal;

// attributs en sortie
out vec3 interpolationPosition;
out vec3 interpolationNormal;

// attributs uniformes
uniform mat4x4 modelViewMatrix;
uniform mat4x4 projectionMatrix;

void main()
{
  // calculer la matrice normale
  mat4x4 normalMatrix = transpose(inverse(modelViewMatrix));

  // transformation de la normale du sommet dans l'espace de vue
  interpolationNormal = vec3(normalMatrix * normal);

  // transformation de la position du sommet dans l'espace de vue
  interpolationPosition = vec3(modelViewMatrix * position);

  // transformation de la position du sommet par les matrices de modèle, vue et projection
  gl_Position = projectionMatrix * modelViewMatrix * position;
}
