# Firebase CRUD Example (Lightweight)

[한국어](#한국어) | [English](#english)

---

## 한국어

ESP32에서 Firebase Realtime Database CRUD 작업을 수행하는 경량화된 예제입니다.
AI로 제작되었습니다.

### 빌드 & 플래시

```bash
idf.py build
idf.py flash
idf.py monitor
```

### 설정

`main/main.c`에서 WiFi와 Firebase 정보를 수정하세요:

```c
// WiFi 설정
.ssid = "your_wifi_ssid",
.password = "your_wifi_password"

// Firebase 설정  
.host = "your-project.firebasedatabase.app",
.api_key = "your_api_key"
```

### 프로젝트 구조

```
├── components/
│   ├── firebase/    # Firebase 클라이언트
│   └── wifi/        # WiFi 매니저
└── main/
    └── main.c       # 메인 애플리케이션
```

### 주요 기능

- **CREATE**: `firebase_set_data()` - 데이터 생성
- **READ**: `firebase_get_data()` - 데이터 읽기
- **UPDATE**: `firebase_set_data()` - 데이터 업데이트
- **DELETE**: `firebase_delete_data()` - 데이터 삭제

### 특징

- 🚀 **경량화**: 39줄의 간결한 코드
- ⚡ **빠른 실행**: 불필요한 지연 제거
- 💾 **메모리 효율**: 8KB 스택 사용
- 📦 **모듈화**: 재사용 가능한 컴포넌트 구조

---

## English

A lightweight example demonstrating Firebase Realtime Database CRUD operations on ESP32.
Created with AI assistance.

### Build & Flash

```bash
idf.py build
idf.py flash
idf.py monitor
```

### Configuration

Modify WiFi and Firebase settings in `main/main.c`:

```c
// WiFi Configuration
.ssid = "your_wifi_ssid",
.password = "your_wifi_password"

// Firebase Configuration  
.host = "your-project.firebasedatabase.app",
.api_key = "your_api_key"
```

### Project Structure

```
├── components/
│   ├── firebase/    # Firebase client
│   └── wifi/        # WiFi manager
└── main/
    └── main.c       # Main application
```

### Key Features

- **CREATE**: `firebase_set_data()` - Create data
- **READ**: `firebase_get_data()` - Read data
- **UPDATE**: `firebase_set_data()` - Update data
- **DELETE**: `firebase_delete_data()` - Delete data

### Highlights

- 🚀 **Lightweight**: Clean 39-line codebase
- ⚡ **Fast Execution**: Minimal delays and logging
- 💾 **Memory Efficient**: 8KB stack usage
- 📦 **Modular**: Reusable component architecture

### Requirements

- ESP32 development board
- WiFi connection
- Firebase Realtime Database project

### Usage Example

```c
// Simple CRUD operations
firebase_set_data("/sensors/temp", "25");    // CREATE
firebase_get_data("/sensors/temp");          // READ
firebase_set_data("/sensors/temp", "30");    // UPDATE
firebase_delete_data("/sensors/temp");       // DELETE
```
