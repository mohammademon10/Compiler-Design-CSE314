<div align="center">

<!-- Banner -->
<img src="" alt="Compiler Design CSE314 Banner" width="100%"/>

# 🛠️ Compiler Design — CSE314

**A hands-on journey through lexical analysis, parsing, and compiler construction.**

[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Flex](https://img.shields.io/badge/Tool-Flex-EF4444?style=for-the-badge&logo=gnu&logoColor=white)](https://github.com/westes/flex)
[![Bison](https://img.shields.io/badge/Tool-Bison-F59E0B?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/bison/)
[![License](https://img.shields.io/badge/License-MIT-10B981?style=for-the-badge)](LICENSE)
[![Stars](https://img.shields.io/github/stars/mohammademon10/Compiler-Design-CSE314?style=for-the-badge&color=8B5CF6)](https://github.com/mohammademon10/Compiler-Design-CSE314/stargazers)

<br/>

<p>
  <a href="#-overview">Overview</a> •
  <a href="#-features">Features</a> •
  <a href="#%EF%B8%8F-tech-stack">Tech Stack</a> •
  <a href="#-project-structure">Project Structure</a> •
  <a href="#-build--run">Build & Run</a> •
  <a href="#-example-output">Example Output</a> •
  <a href="#-what-i-learned">What I Learned</a> •
  <a href="#-contributing">Contributing</a> •
  <a href="#-author--contact">Author</a>
</p>

</div>

---

## 📖 Overview

This repository is a comprehensive collection of coursework, labs, and mini-projects from the **Compiler Design (CSE314)** course. It covers the foundational concepts of compiler construction — from **lexical analysis** with hand-written C programs, to **scanner generation** with Flex, to **parser construction** with Bison.

Whether you're a fellow student looking for reference material, or a curious developer wanting to understand how compilers work under the hood, this repo has something for you. Each directory is self-contained with source files, build artifacts, and documentation.

---

## ✨ Features

| Category | Highlights |
|:---------|:-----------|
| 🔤 **Lexical Analysis** | Hand-written tokenizers in C — keywords, identifiers, operators, comments |
| ⚡ **Flex (Scanner Generator)** | `.l` files demonstrating pattern matching, token recognition, and lexer rules |
| 🌳 **Bison (Parser Generator)** | `.y` files with grammar rules, AST construction, and syntax-directed translation |
| 🧮 **Calculator Parser** | Full arithmetic expression evaluator with operator precedence |
| 🔀 **Boolean Expression Parser** | Recognizes and evaluates boolean logic expressions |
| 🔁 **If-Else Parser** | Parses conditional control-flow syntax |
| 📋 **List Processor** | Parses and processes structured list input |
| 📝 **Weekly Lab Reports** | Progressive exercises building toward full lexical analysis |
| 📄 **Comprehensive Documentation** | PDF reports, lab manuals, and notes included |

---

## 🛠️ Tech Stack

<div align="center">

| Tool | Purpose |
|:----:|:--------|
| <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="30"/> **C** | Core implementation language |
| 🦊 **Flex** | Lexical analyzer (scanner) generator |
| 🦬 **Bison** | Parser generator (LALR) |
| 🐧 **GCC** | GNU C Compiler for building executables |
| 📄 **Make** | Build automation (optional) |

</div>

---

## 📁 Project Structure

```
Compiler-Design-CSE314/
│
├── 📄 README.md
├── 🖼️ assets/
│   └── banner.png
│
├── 📂 Flex_&_Bison_Lab/              # ⚡ Core Flex & Bison labs
│   ├── lab_01_flex/                   #    └─ Basic Flex lexer (token recognition)
│   │   ├── abcd.l                     #       Flex source with keyword/number rules
│   │   └── basic_syntax_of_flex       #       Syntax reference notes
│   │
│   ├── lab_02/                        #    └─ Lexer + Parser combo
│   │   ├── lexer.l                    #       Flex scanner
│   │   └── parser.y                   #       Bison grammar
│   │
│   ├── lab_03/                        #    └─ Full Flex-Bison integration
│   │   ├── abc.l                      #       Flex scanner
│   │   ├── abc.y                      #       Bison parser
│   │   └── baison_basic_&_Syntax      #       Quick reference notes
│   │
│   ├── Lab_Task_02/                   #    └─ 🎯 Mini-Projects
│   │   ├── Task_01/                   #       🧮 Calculator (arithmetic parser)
│   │   │   ├── calc.l
│   │   │   └── calc.y
│   │   ├── Task_02/                   #       📝 Assignment & expression parsing
│   │   ├── Task_03/                   #       🔀 Boolean expression parser
│   │   ├── Task_4/                    #       🔁 If-else control flow parser
│   │   └── Task_5/                    #       📋 List processing parser
│   │
│   └── Flex_&_Bison_All_Notes_&_Documents/
│       ├── Flex Bison Lab Manual.pdf
│       ├── Flex Installation Guide.pdf
│       ├── flex and bison flow diagram.pdf
│       └── flex_bison_boolean_if_else_parser.pdf
│
├── 📂 LAB_REPORT/                     # 📄 Formal Lab Reports (PDF/DOCX)
│   ├── CD_Lab_01_04_Emon_818.pdf
│   ├── Compiler_Lab_Report_05_10_Flex_Bison.pdf
│   └── Compilerlabreport.docx
│
├── 📂 week-01/                        # 📅 Week 1 — String Operations in C
│   ├── P1_string_len.c
│   ├── P2_String_copy.C
│   ├── p3_concataning_two_string.c
│   ├── p4_comparing_two_string.c
│   └── p5_reverse_string.c
│
├── 📂 week-02/                        # 📅 Week 2 — Whitespace & Tokenization
│   ├── p1_Whatespace.c
│   ├── p2.isspace.c
│   ├── p3_Count_Whitespace.c
│   ├── p4_remove_Whitespace.c
│   └── p5_tokenization.c
│
├── 📂 week-03/                        # 📅 Week 3 — Lexical Analysis Programs
│   ├── p1_identifi_intiger_from_string.c
│   ├── p2_identify_keywords.c
│   ├── p3_identifiyer.c
│   ├── p4_valididentifier_check.c
│   ├── P5_Operators.c
│   ├── P6_special_Symbols.c
│   ├── p7_Extract_Comments.C
│   ├── Lexical_Analysis_use_Function.c
│   └── lexical_analysis_mini_programme.c
│
└── 📂 week-04/                        # 📅 Week 4 — Regex & Advanced Parsing
    ├── Lab_task_regular_expression.c
    ├── Regular_expression_using_function.c
    └── lexical_analysis.c
```

---

## 🚀 Build & Run

### Prerequisites

Make sure you have the following installed:

| Tool | Install Command (Ubuntu/Debian) | Windows |
|:-----|:-------------------------------|:--------|
| GCC | `sudo apt install gcc` | [MinGW](https://www.mingw-w64.org/) |
| Flex | `sudo apt install flex` | [WinFlexBison](https://github.com/lexxmark/winflexbison) |
| Bison | `sudo apt install bison` | [WinFlexBison](https://github.com/lexxmark/winflexbison) |

### Building a Flex + Bison Project

```bash
# 1. Navigate to the project directory
cd Flex_&_Bison_Lab/Lab_Task_02/Task_01/

# 2. Generate the parser
bison -d calc.y

# 3. Generate the scanner
flex calc.l

# 4. Compile everything together
gcc lex.yy.c calc.tab.c -o calc -lfl

# 5. Run the calculator
./calc
```

### Building a C-only Program

```bash
# Navigate to any weekly exercise
cd week-03/

# Compile and run
gcc lexical_analysis_mini_programme.c -o lexer
./lexer
```

---

## 🖥️ Example Output

### 🧮 Calculator Parser (`Task_01`)

```
$ ./calc
Enter expression:
3 + 5 * 2
= 13
(10 - 4) / 2
= 3
```

### 🔤 Flex Lexer (`lab_01_flex`)

```
$ ./lexer
int x = 42 + 3.14 end

keyword: int
Identifier: x
Operator: =
Number : 42
Count : 1
Operator: +
Float : 3.14
Count : 2
```

### 📝 Lexical Analysis (Week 3 — C Implementation)

```
$ ./lexer
Enter source code: int main() { return 0; }

Keywords:   int, return
Identifiers: main
Operators:  (none)
Symbols:    ( ) { ; }
Numbers:    0
```

---

## 🧠 What I Learned

<table>
  <tr>
    <td width="50%">

**Compiler Theory**
- How compilers break source code into tokens (lexical analysis)
- Context-free grammars and BNF notation
- LALR parsing and shift-reduce strategies
- Syntax-directed translation and semantic actions

</td>
<td width="50%">

**Practical Skills**
- Writing regular expressions for token patterns
- Designing `.l` (Flex) files for scanner generation
- Defining `.y` (Bison) files with grammar rules
- Debugging parser conflicts and ambiguous grammars

</td>
  </tr>
  <tr>
    <td>

**C Programming**
- String manipulation and memory management
- File I/O and stream processing
- Building tokenizers from scratch
- Working with function pointers and enums

</td>
<td>

**Tooling & Workflow**
- Unix build pipelines (Flex → Bison → GCC)
- Reading and understanding generated C code
- Version control with Git for academic projects
- Writing clear documentation and lab reports

</td>
  </tr>
</table>

---

## 🤝 Contributing

Contributions, improvements, and suggestions are always welcome! Here's how you can help:

1. **🍴 Fork** the repository
2. **🌿 Create** a feature branch
   ```bash
   git checkout -b feature/your-improvement
   ```
3. **💻 Commit** your changes
   ```bash
   git commit -m "Add: your improvement description"
   ```
4. **🚀 Push** to the branch
   ```bash
   git push origin feature/your-improvement
   ```
5. **📬 Open** a Pull Request

### 💡 Ideas for Contributions

- Add more parser examples (e.g., `while` loops, function declarations)
- Create a `Makefile` for easy one-command builds
- Add syntax diagrams or railroad diagrams for grammars
- Write unit tests for the parsers
- Translate documentation to other languages

---

## 👤 Author & Contact

<div align="center">

| | |
|:--|:--|
| 👨‍💻 **Name** | Md. Emon Hossain |
| 🎓 **Department** | Computer Science & Engineering (CSE) |
| 📧 **Email** | [emonemran677@gmail.com](mailto:emonemran677@gmail.com) |
| 🐙 **GitHub** | [@mohammademon10](https://github.com/mohammademon10) |

</div>

---

<div align="center">

### ⭐ Show Your Support

If this repository helped you understand compiler design concepts or saved you time on coursework,<br/>
**please consider giving it a star!** Every ⭐ motivates me to keep improving and sharing.

[![Star this repo](https://img.shields.io/github/stars/mohammademon10/Compiler-Design-CSE314?style=for-the-badge&label=Star%20This%20Repo&color=F59E0B&logo=github)](https://github.com/mohammademon10/Compiler-Design-CSE314)

<br/>

<sub>Made with ❤️ for the open-source and academic community</sub>

<sub>© 2026 Md. Emon Hossain — CSE314 Compiler Design</sub>

</div>
