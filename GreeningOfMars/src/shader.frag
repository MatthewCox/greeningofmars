uniform sampler2D marsHeightmap;

varying vec3 lightPosition;
varying vec3 normal;

void main()
{
	float lightDiffuse = max(dot(normal, lightPosition), 0.0);
	gl_FragColor = gl_Color * lightDiffuse * texture2D(marsHeightmap, gl_TexCoord[0].xy);
}