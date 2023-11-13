import os
from pathlib import Path


def get_title() -> str:
    md = "# ESTRUTURA DE DADOS E ALGORITMOS 1\n\n"

    return md


def get_syllabus() -> str:
    md = """## :book: Ementa\n
<div>
    <details>
        <summary>Ponteiros e alocação dinâmica de memória.</summary>
    </details>
    <details>
        <summary>Princípios da análise de algoritmos</summary>
        <ul>
            <li>Complexidade computacional.</li>
            <li>Análise assintótica: notação Big-O.</li>
        </ul>
    </details>
    <details>
        <summary>Recursão</summary>
        <ul>
            <li>Algoritmos recursivos</li>
            <li>Método da divisão e conquista</li>
        </ul>
    </details>
    <details>
        <summary>Estrutura de dados</summary>
        <ul>
            <li>Elementares (lineares):</li>
                <ul>
                    <li>Arrays e listas</li>
                    <li>Listas encadeadas.</li>
                </ul>
            <li>Tipos abstratos de dados</li>
                <ul>
                    <li>Filas</li>
                    <li>Pilhas</li>
                    <li>Árvores binárias</li>
                </ul>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de ordenação</summary>
        <ul>
            <li>Métodos elementares:</li>
                <ul>
                    <li>Selection Sort</li>
                    <li>Insertion Sort</li>
                    <li>Bubble Sort</li>
                </ul>
            <li>Quicksort</li>
            <li>Mergesort</li>
            <li>Filas de prioridades e heapsort</li>
            <li>Radix sorting</li>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de busca</summary>
        <ul>
            <li>Busca sequencial</li>
            <li>Busca binária</li>
            <li>Árvores de busca binária</li>
        </ul>
    </details>
</div>\n
"""

    return md


def valid_section(section: Path) -> bool:
    return section.is_dir()


def get_section_name(section: str) -> str:
    return section.replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".c"))


def get_lists_name(list_file: str) -> str:
    name, _ = list_file.split(".")
    name = name.replace("-", " ")
    name = name.replace("_", " ")
    return name.title()


def get_relative_path(file: Path) -> str:
    return str(file).split("..")[1]


def get_exercises_md() -> str:
    listPath = Path(__file__).parent / ".." / "listas"
    output = list()
    for section in os.listdir(listPath):
        if valid_section(listPath / section):
            current = {"name": get_section_name(section), "lists": list()}
            for code_section in os.listdir(listPath / section):
                if code_section != "code":
                    continue

                for list_file in os.listdir(listPath / section / code_section):
                    if valid_file(listPath / section / code_section / list_file):
                        current["lists"].append(
                            {
                                "name": get_lists_name(list_file),
                                "path": get_relative_path(listPath / section / code_section / list_file),
                            }
                        )

                current["lists"] = sorted(
                    current["lists"], key=lambda x: x["name"]
                )
                output.append(current)

    output = sorted(output, key=lambda x: x["name"])
    md = "## :computer: Listas de execícios\n\n<div>\n"
    for section in output:
        md += f"    <details>\n        <summary>Lista {section['name']}</summary>\n"
        md += "        <ul>\n"
        for code_section in section["lists"]:
            md += f"            <li><a target='_self' href='https://github.com/unbytes/eda1/tree/main{code_section['path']}'>{code_section['name']}</a></li>\n"

        md += "    </ul>\n    </details>\n"
    
    md += "</div>\n\n"

    return md


def get_teacher() -> str:
    md = """## :man_teacher: Professora\n
- [Rose Yuri Shimizu](https://sigaa.unb.br/sigaa/public/docente/portal.jsf?siape=1276557)\n
"""

    return md


def get_references() -> str:
    md = """## :books: Referências\n
- [Plano de Ensino](https://fga.rysh.com.br/eda1/)
- Robert Sedgewick Algorithms in C, Addison Wesley, 3nd ed.
- [Algorithms, 4th Edition - Robert Sedgewick e Kevin Wayne](https://algs4.cs.princeton.edu/home/)
- [Prof. Bruno Ribas](https://www.brunoribas.com.br/)
- [Prof. Paulo Feofiloff](https://www.ime.usp.br/~pf/algoritmos/index.html#C-language)
- Thomas H. Cormen et al Algoritmos - Teoria e Prática, Elsevier, 3nd ed.\n
"""

    return md


def get_observation() -> str:
    md = """## :dart: Observações\n
Para compilar os códigos que utilizam as bibliotecas customizadas da pasta `libs` é necessário utilizar o seguinte comando:

```bash
gcc -I libs -o listas/XX/code/output/YY listas/XX/code/YY.c

./listas/XX/code/output/YY
```

Em que `XX` é o número da lista e `YY` é o número do exercício."""

    return md


def build_md() -> str:
    md = ""
    md += get_title()
    md += get_syllabus()
    md += get_exercises_md()
    md += get_teacher()
    md += get_references()
    md += get_observation()
    return md


print(build_md())
