#include <stdio.h>

// Bir float 32 bittir. Bu union ile aynı 32 bite
// hem sayı (f) hem de bit dizisi (ui) olarak erişiriz.
union float_caster {
    float f;
    unsigned int ui;
};

void print_float_bits(float num) {
    union float_caster caster;
    caster.f = num;

    printf("Sayı: %f\n", num);
    printf("Bit Dizilimi: ");

    for (int i = 31; i >= 0; i--) {
        // Bitleri tek tek kontrol et (Bitwise Shift)
        int bit = (caster.ui >> i) & 1;
        printf("%d", bit);

        // Bölümleri görsel olarak ayır (Sign | Exponent | Mantissa)
        if (i == 31) printf(" | ");      // 1 bit Sign
        else if (i == 23) printf(" | "); // 8 bit Exponent
    }
    printf("\n");
    printf("Yapı: [İşaret] | [Üs (Bias ile)] | [Mantis]\n\n");
}

int main() {
    print_float_bits(1.0f);   // Tam 1.0
    print_float_bits(-1.0f);  // İşaret bitinin değişimini gör
    print_float_bits(0.5f);   // Üssün (exponent) nasıl küçüldüğünü gör
    print_float_bits(0.0f);   // Özel durum: Hepsi sıfır
	print_float_bits(13.125);
    return 0;
}