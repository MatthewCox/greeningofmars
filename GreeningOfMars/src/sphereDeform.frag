uniform sampler2D marsHeightmap;

varying vec3 LightDirection;
varying vec3 ViewDirection;
varying vec3 Normal;

void main()
{
	vec4 lightDiffuse = gl_Color * max(dot(Normal, LightDirection), 0.0);
	lightDiffuse += max(dot(Normal, LightDirection), 0.1);
	lightDiffuse.w = 1.0;
	vec4 texColor = texture2D(marsHeightmap, gl_TexCoord[0].xy);
	gl_FragColor = texColor * lightDiffuse;
}