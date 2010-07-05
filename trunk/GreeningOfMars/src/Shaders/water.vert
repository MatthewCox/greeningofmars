varying vec3 ViewDirection;
varying vec3 LightDirection;

attribute vec3 Tangent;

varying vec2 TexCoord;

void main()
{
	ViewDirection = vec3(gl_ModelViewMatrix * gl_Vertex);
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	TexCoord = gl_MultiTexCoord0.xy;
	
	vec3 n = normalize(gl_NormalMatrix * gl_Normal);
	vec3 t = normalize(gl_NormalMatrix * Tangent);
	vec3 b = cross(n, t);
	
	vec3 LightPosition = gl_LightSource[0].position.xyz;
	
	vec3 v;
	v.x = dot(LightPosition, t);
	v.y = dot(LightPosition, b);
    v.z = dot(LightPosition, n);
    LightDirection = normalize(v);
    
    v.x = dot(ViewDirection, t);
	v.y = dot(ViewDirection, b);
    v.z = dot(ViewDirection, n);
    ViewDirection = normalize(v);
	
	gl_FrontColor = gl_Color;
}