uniform sampler2D waterNormal;
uniform float Time;

varying vec3 ViewDirection;
varying vec3 LightDirection;
varying vec2 TexCoord;

void main()
{
	vec3 SurfaceColour = vec3(0.0, 0.2, 0.5);
	float Specular = 0.5;
	
	vec3 litColour;
	
	vec2 fTexCoord = fract(TexCoord*50.0 + Time*0.1);
	
	vec3 normal = normalize((2.0 * texture2D(waterNormal, fTexCoord).xyz - 1.0));
	
	vec3 lightDiffuse = SurfaceColour * max(dot(normal, LightDirection), 0.0);
	litColour = lightDiffuse;
	gl_FragColor = vec4(litColour, 1.0);
}