# IEEEXtreme 13.0

[IEEEXtreme](https://ieeextreme.org/) is a global challenge in which teams of IEEE Student members – advised and proctored by an IEEE member, and often supported by an IEEE Student Branch – compete in a 24-hour time span against each other to solve a set of programming problems.

` These team scored Top 10 in the National Portugal's Leadership board `
## Authors
* Gonçalo Marantes - [Marantesss](https://github.com/Marantesss) 
* Beatriz Garrido - [bgarrido7](https://github.com/bgarrido7)
* Cajó Alburquerque - [CajoAlbuquerque](https://github.com/CajoAlbuquerque)

# Pyhton Stuff

## Creating virtual environments

### Pyhton 3.6 and above

**venv** comes built in with Python3.6 and above

```shell
python3 -m venv env # env -> environment name
```
### Python 3.5 and below

```shell
pip install virtualenv
virtualenv env
```

## Using virtual environments

### Ligate

```shell
source env/bin/activate
```

### Desligate

```shell
deactivate
```

## How to use requirement files:

### Export

```shell
pip freeze > requirements.txt
```

### Import

```shell
pip install -r requirements.txt
```

