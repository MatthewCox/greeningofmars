uniform sampler2D marsHeightmap;

varying vec3 LightDirection;
varying vec3 Normal;

void main()
{
	float lightDiffuse = max(dot(Normal, LightDirection), 0.0);
	lightDiffuse = lightDiffuse * 0.3;
	gl_FragColor = gl_Color * lightDiffuse * texture2D(marsHeightmap, gl_TexCoord[0].xy);
}