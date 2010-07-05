uniform sampler2D marsHeightmap;

varying vec3 LightPosition;
varying vec3 Normal;

void main()
{
	float lightDiffuse = max(dot(Normal, LightPosition), 0.0) * 3.0;
	vec4 texColor = texture2D(marsHeightmap, gl_TexCoord[0].xy);
	gl_FragColor.w = 1.0;
	gl_FragColor.xyz = (gl_Color * texColor * (lightDiffuse + 0.1)).xyz;
}