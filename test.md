#  Test-Case
## Redirection



### TEST - 1
```bash
echo a >t1 >test >t2 | cat | cat
```
**Error:** `bash: test: Permission denied`
#### Bu komut execute edildiğinde izinsiz dosyaya kadar dosyaları oluşturur izinsiz dosya gördüğü zaman hata verip durur.

---

### TEST - 2
```bash
echo a >t1 >test | sleep 10
```
**Error:** `bash: test: Permission denied`
#### Her komut kendi hatasını kendi içinde yaşar. Yani Pipe'ın diğer tarafında işler devam eder.(Bu bir redirection işlemi olsa bile)


