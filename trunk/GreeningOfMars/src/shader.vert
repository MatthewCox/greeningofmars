//uniform sampler2D marsHeightmap;

void main()
{
	vec4 pos = vec4(gl_Vertex);
	//vec4 tex = texture2D(marsHeightmap, vec2(pos.x * 0.1, pos.z * 0.1));
	//vec3 normal = gl_Normal;
	//pos.xyz = pos.xyz + (normal.xyz * tex.rgb * 5.0);
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * pos;
}