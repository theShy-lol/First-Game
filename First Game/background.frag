uniform float uTime;
uniform vec2 uResolution; // e.g. vec2(800.0, 600.0)

void main()
{
    // Normalized screen coordinates (0.0 at bottom-left to 1.0 at top-right)
    vec2 uv = gl_FragCoord.xy / uResolution;

    // Center coordinates (-0.5 to 0.5) for vignette
    vec2 centerUV = uv - 0.5;

    // Dark base backdrop colors (deep space navy / dark obsidian)
    vec3 deepBg    = vec3(0.02, 0.02, 0.05);
    vec3 midGlow   = vec3(0.04, 0.03, 0.10);
    vec3 gridColor = vec3(0.18, 0.10, 0.35); // Dim retro violet grid

    // --- 1. Subtle Radial Glow in Center ---
    float centerDist = length(centerUV);
    vec3 col = mix(midGlow, deepBg, centerDist * 1.2);

    // --- 2. Scrolling Grid Lines ---
    // Scale UV to grid cell count (e.g. 24 horizontal divisions)
    vec2 gridUV = uv * vec2(24.0, 18.0);
    gridUV.y += uTime * 0.4; // Slowly scrolls downward

    // Draw thin grid lines
    vec2 gridFract = abs(fract(gridUV - 0.5) - 0.5) / fwidth(gridUV);
    float line = min(gridFract.x, gridFract.y);
    float gridIntensity = 1.0 - min(line, 1.0);

    // Blend grid into background very softly
    col += gridColor * (gridIntensity * 0.22);

    // --- 3. Dark Vignette at the edges ---
    // Darkens screen corners to make the playing field focus in the middle
    float vignette = 1.0 - smoothstep(0.4, 0.85, centerDist);
    col *= vignette;

    gl_FragColor = vec4(col, 1.0);
}