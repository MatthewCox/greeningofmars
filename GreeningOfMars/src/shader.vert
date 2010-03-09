//uniform sampler2D marsHeightmap;

varying vec3 lightPosition;
varying vec3 normal;

void main()
{
	vec4 pos = vec4(gl_Vertex);
	//vec4 tex = texture2D(marsHeightmap, vec2(pos.x * 0.1, pos.z * 0.1));
	normal = normalize(gl_NormalMatrix  * gl_Normal);
	lightPosition = gl_LightSource[0].position.xyz;
	//pos.xyz = pos.xyz + (normal.xyz * tex.rgb * 5.0);
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * pos;
}