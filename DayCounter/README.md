# VS Code — skrót do uruchamiania programu

Aby szybko uruchamiać skompilowany program, skonfiguruj skrót klawiaturowy dla zadania **Run**.

## 1. Otwórz konfigurację skrótów klawiaturowych

W VS Code naciśnij:

```text
Ctrl + Shift + P
```

Wyszukaj:

```text
Preferences: Open Keyboard Shortcuts (JSON)
```

i wybierz tę opcję.

## 2. Dodaj skrót

Do pliku `keybindings.json` dodaj:

```json
{
    "key": "ctrl+shift+r",
    "command": "workbench.action.tasks.runTask",
    "args": "Run"
}
```

Jeżeli plik zawiera już inne skróty, dodaj nowy wpis do istniejącej tablicy:

```json
[
    {
        "key": "ctrl+shift+r",
        "command": "workbench.action.tasks.runTask",
        "args": "Run"
    }
]
```

## 3. Kompilowanie i uruchamianie

Od tej chwili możesz korzystać ze skrótów:

| Skrót | Działanie |
|---|---|
| `Ctrl + Shift + B` | Kompiluje program C++ |
| `Ctrl + Shift + R` | Uruchamia zadanie `Run` |

Skrót `Ctrl + Shift + R` zakłada, że w pliku `.vscode/tasks.json` istnieje zadanie o nazwie `"Run"`.