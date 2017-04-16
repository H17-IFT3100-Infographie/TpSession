// IFT3100H17 ~ BlinnPhongFS.glsl

#version 330

// attributs interpolés à partir des valeurs en sortie du shader de sommet
in vec3 interpolationPosition;
in vec3 interpolationNormal;

// attribut en sortie
out vec4 fragmentColor;

// couleurs de réflexion du matériau
uniform vec3 colorAmbient;
uniform vec3 colorDiffuse;
uniform vec3 colorSpecular;

// facteur de brillance spéculaire du matériau
uniform float brightness;

// position d'une source de lumière
uniform vec3 lightPosition;

void main()
{
  // re-normaliser la normale après interpolation
  vec3 N = normalize(interpolationNormal);

  // calculer la direction de la surface vers la lumière (L)
  vec3 L = normalize(lightPosition - interpolationPosition);

  // calculer le niveau de réflexion diffuse (N • L)
  float reflectionDiffuse = max(dot(N, L), 0.0);

  // réflexion spéculaire par défaut
  float reflectionSpecular = 0.0;

  // calculer la réflexion spéculaire seulement s'il y a réflexion diffuse
  if(reflectionDiffuse > 0.0)
  {
    // calculer la direction de la surface vers la caméra (V)
    vec3 V = normalize(-interpolationPosition);

    // calculer la direction du demi-vecteur de réflection (H) en fonction du vecteur de vue (V) et de lumière (L)
    vec3 H = normalize(V + L);

    // calculer la réflexion spéculaire entre (R dot V)
    reflectionSpecular = pow(max(dot(N, H), 0.0), brightness);
  }

  // calculer la couleur du fragment
  fragmentColor = vec4(
    colorAmbient  +
    colorDiffuse  * reflectionDiffuse +
    colorSpecular * reflectionSpecular, 1.0);
}
