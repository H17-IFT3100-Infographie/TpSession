// IFT3100H17 ~ LambertFS.glsl

#version 330

// attributs interpolés à partir des valeurs en sortie du shader de sommet
in vec3 interpolationPosition;
in vec3 interpolationNormal;

// attribut en sortie
out vec4 fragmentColor;

// couleurs de réflexion du matériau
uniform vec3 colorAmbient;
uniform vec3 colorDiffuse;

// position d'une source de lumière
uniform vec3 lightPosition;

void main()
{
  // re-normaliser la normale après inteolation (N)
  vec3 N = normalize(interpolationNormal);

  // calculer la direction de la surface vers la lumière (L)
  vec3 L = normalize(lightPosition - interpolationPosition);

  // calculer le niveau de réflexion diffuse (N • L)
  float reflectionDiffuse = max(dot(N, L), 0.0);

  // déterminer la couleur du fragment
  fragmentColor = vec4(colorAmbient + colorDiffuse * reflectionDiffuse, 1.0);
}
