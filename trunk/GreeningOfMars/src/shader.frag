uniform sampler2D marsHeightmap;

void main()
{
	gl_FragColor = texture2D(marsHeightmap, gl_TexCoord[0].xy);
}