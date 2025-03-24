# Image Processing in C++

This is an object-oriented image processing library implemented in C++. 
It supports grayscale `.pgm` (ASCII) images and includes features like contrast/brightness adjustment, gamma correction, image convolution, and region of interest (ROI) extraction.

---

## ✅ Implemented Features

- 📦 `Image` class 
- 🟰 `Size`, `Point`, `Rectangle` helper classes
- 🌗 **Brightness and Contrast Adjustment**
- 📈 **Gamma Correction**
- 🔁 **Convolution Filters**
- 🔍 **ROI (Region of Interest)** 
- 💾 Load/Save from/to `.pgm` files (P2 ASCII format)
- 🧪 Fully tested with assertions for all major operations

---

## 🛠️ Build & Run

```bash
git clone https://github.com/your-username/Image-Processing-in-C-.git
cd Image-Processing-in-C-
mkdir build && cd build
cmake ..
make
./Image_Processing_in_C_
```

## Tests

- Tests are defined using assert() and cover:
- Constructors and image data handling
- Pixel access and manipulation
- Transform correctness (gamma, brightness, convolution)
- ROI behavior

All processed images from tests (e.g., gamma correction, contrast, convolution) are saved in the `assets/newAssets/` directory.

