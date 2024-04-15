void main() {
    char* video_memory = (char*) 0xb8000;  // Pointer to video memory
    *video_memory = 'X';                   // Write 'X' at the top-left of the screen
}
