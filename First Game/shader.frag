uniform float uTime;

// Simple 1D pseudo-random hash
float hash(float n) 
{
    return fract(sin(n) * 43758.5453123);
}

void main()
{
    vec2 uv = gl_TexCoord[0].xy;

    // --- FLICKER CALCULATION ---
    // 1. High-frequency random jitter (steps 30 times a second for twitchy electricity)
    float timeStep = floor(uTime * 30.0);
    float jitter = hash(timeStep) * 0.25;

    // 2. Multi-frequency surges (prevents repetitive sine motion)
    float surge = sin(uTime * 14.0) * 0.08 + cos(uTime * 27.0) * 0.05;

    // 3. Occasional sudden drops (stutters)
    float stutter = step(0.92, hash(timeStep * 1.7)) * -0.2;

    // Combined flicker factor
    float flicker = 1.0 + jitter + surge + stutter;
    // ---------------------------

    // Distance from the horizontal center (0.0 at center, 1.0 at edges)
    float distFromCenter = abs(uv.y - 0.5) * 2.0;

    // Pulse moving down the beam, modulated by global flicker
    float pulse = (0.95 + 0.05 * sin(uv.x * 25.0 - uTime * 6.0)) * flicker;

    // Core laser (bright center) - flickers slightly less to maintain punch
    float core = pow(max(1.0 - distFromCenter, 0.0), 12.0) * 1.5 * (1.0 + jitter * 0.5);

    // Outer neon glow - flickers intensely
    float glow = pow(max(1.0 - distFromCenter, 0.0), 2.2) * 1.2 * pulse;

    // Soft fade at the ends
    float capFade = smoothstep(0.0, 0.05, uv.x) * smoothstep(1.0, 0.95, uv.x);

    // Palette
    vec3 deepBlue  = vec3(0.05, 0.25, 0.95);
    vec3 cyanGlow  = vec3(0.00, 0.75, 1.00);
    vec3 whiteCore = vec3(0.85, 0.95, 1.00);

    // Combine
    vec3 finalColor = mix(deepBlue, cyanGlow, glow) + (whiteCore * core);
    float alpha = clamp(glow + core, 0.0, 1.0) * capFade;

    gl_FragColor = vec4(finalColor, alpha);
}