# ChangeMe

### Start

 - with [`gh`](https://github.com/cli/cli) (preferred)

```console
gh repo create ChangeMe --template hugsy/modern-cpp-template --clone # --private
```

 - with `git`
```console
git clone --depth 1 -q https://github.com/hugsy/modern-cpp-template ChangeMe
```



### Configure

Replace all `ChangeMe` values

```console
cd ChangeMe
```

Then
```console
cmake -S . -B build -T host=x64 -A x64
cmake --build build
```



### Build


```console
cmake --build ./build
```
