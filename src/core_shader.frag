uniform sampler2D u_texture;
uniform vec2 u_lightPosition;

varying vec4 v_vertPos;

void main()
{
    float constant = 1.0;
    float linear = 0.09;
    float quadratic = 0.032;

    vec2 light_position = (gl_ModelViewProjectionMatrix * vec4(u_lightPosition, 0, 1)).xy;

    float lightDistance = length(light_position - v_vertPos.xy);
    float attenuation = 1.0 / (constant + linear *lightDistance + quadratic * (lightDistance * lightDistance));

    vec4 ambient = vec4(0.02, 0.02, 0.6, 1);

    // lookup the pixel in the texture
    vec4 pixel = texture2D(u_texture, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = gl_Color * pixel * attenuation;
}