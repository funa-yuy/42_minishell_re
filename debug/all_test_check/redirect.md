# リダイレクト
### - 問題点
	- クォートのみで実行した際、エラー文がなぜか"Permission denied"になる→commandのテストケース側での問題と同じ
#### - 構文 cmd > path | cmd >path | cmd> path | cmd>path
	echo Hello > out
	echo Hello >out
	echo Hello>out
	echo Hello>out

## シンタックスエラー
- `<`
	→ bash: syntax error near unexpected token `newline'にする
- `>`
	→ bash: syntax error near unexpected token `newline'にする
- `<<`
	→ bash: syntax error near unexpected token `newline'にする
- `>>`
	→ bash: syntax error near unexpected token `newline'にする
- !! `<<<`
	→ bash: syntax error near unexpected token `<'にする
- `>>>`
	→ bash: syntax error near unexpected token `>'にする



## > 出力
### `<` `<<` `>` 共通のテスト項目
#### - リダイレクトと pathのみ | クォートのみ | 空白
	> out
	"" > out
	"   " > out

#### - pathが 存在する | 存在しない
	echo hello > noexist
	echo hello > exist

#### - pathが 文字列 | 数字 | リダイレクト記号 | パイプ
	echo string > out
	echo number > 123
	echo redirect_symbol > ">"
	echo pipe_symbol > "|"

#### - コマンドが 正常 | オプションあり | オプションが不正 | 存在しないコマンド
	echo 42tokyo > out
	ls -l > out
	ls -0 > out
	aaaa > out

#### - 複数のリダイレクトでcmdが 前 | 中間 | 後ろ
	echo 42tokyo > out > out2
	> out echo 42tokyo > out2
	> out > out2 echo 42tokyo

#### - 複数のリダイレクトでpathが 同じ | 異なる
	echo 42tokyo > out > out
	echo 42tokyo > out > out2

#### - 正常なリダイレクトとエラー エラー→正常 | 正常→エラー
	echo 42Tokyo > out >
	echo 42Tokyo > > out

#### - バイナリを書き込む
	minishell cat | xxd | tail > out
	infile cat | xxd | tail > out

#### - pathの権限 -r | -w | -x
```bash
chmod -r out
echo 42 > out
```
```bash
chmod -x out
echo 42 > out
```
### エラー
```bash
chmod -w out
echo 42 > out
```



## >> 追記
### `<` `<<` `>` 共通のテスト項目
#### - リダイレクトと pathのみ | クォートのみ | 空白
	>> out
	"" >> out
	"   " >> out

#### - pathが 存在する | 存在しない
	echo 42Tokyo >> noexist
	echo 42Tokyo >> exist

#### - pathが 文字列 | 数字 | リダイレクト記号 | パイプ
	echo string >> str
	echo number >> 123
	echo redirect_symbol >> ">>"
	echo pipe_symbol >> "|"

#### - コマンドが 正常 | オプションあり | オプションが不正 | 存在しないコマンド
	echo 42tokyo >> out
	ls -l >> out
	ls -0 >> out
	aaaa >> out

#### - 複数のリダイレクトでcmdが 前 | 中間 | 後ろ
	echo 42tokyo >> out >> out2
	>> out echo 42tokyo >> out2
	>> out >> out2 echo 42tokyo

#### - 複数のリダイレクトでpathが 同じ | 異なる
	echo 42tokyo >> out >> out
	echo 42tokyo >> out >> out2

#### - 正常なリダイレクトとエラー エラー→正常 | 正常→エラー
	echo 42Tokyo >> out >>
	echo 42Tokyo >> >> out

#### - バイナリを書き込む
	minishell cat | xxd | tail >> out
	infile cat | xxd | tail >> out

#### - pathの権限 -r | -w | -x
```bash
	echo 42Tokyo > out
	chmod -r out
	echo hello >> out
```
```bash
	echo 42Tokyo > out
	chmod -w out
	echo hello >> out
```
```bash
	echo 42Tokyo > out
	chmod -x out
	echo hello >> out
```



## < 入力
### `<` `<<` `>` 共通のテスト項目
#### - リダイレクトと pathのみ | クォートのみ | 空白
	< out
	"" < out
	"   " < out

#### - pathが 存在する | 存在しない
	cat < noexist
	cat < exist

#### - pathが 文字列 | 数字 | リダイレクト記号 | パイプ
	cat < out
	cat < 123
	cat < "<"
	cat < "|"

#### - コマンドが 正常 | オプションあり | オプションが不正 | 存在しないコマンド
	cat < out
	grep "42" < out
	grep --invalid-option  < out
	aaaa < out

#### - 複数のリダイレクトでcmdが 前 | 中間 | 後ろ
	cat < out < out2
	< out cat < out2
	< out < out2 cat

#### - 複数のリダイレクトでpathが 同じ | 異なる
	cat < out < out
	cat < out < out2

#### - 正常なリダイレクトとエラー エラー→正常 | 正常→エラー
	cat < out <
	cat < < out

#### - バイナリを読み込む
	< minishell cat | xxd | tail
	< infile cat | xxd | tail

#### - pathの権限 -r | -w | -x
```bash
	echo 42Tokyo > in
	chmod -r in
	cat < in
```
```bash
	echo 42Tokyo > in
	chmod -w in
	cat < in
```
```bash
	echo 42Tokyo > in
	chmod -x in
	cat < in
```



## << ヒアドク
#### - リダイレクトと eofのみ | クォートのみ | 空白
	<< EOF
	"" << EOF
	"   " << EOF

#### - eofが 文字列 | 数字 | リダイレクト記号 | パイプ
	cat << EOF
	cat << 123
	cat << "<<"
	cat << "|"

#### - コマンドが 正常 | オプションあり | オプションが不正 | 存在しないコマンド
	cat << EOF
	grep "42" << EOF
	grep --invalid-option  << EOF
	aaaa << EOF

#### - 正常なリダイレクトとエラー エラー→正常 | 正常→エラー
	cat <<EOF <<
	cat << <<EOF

#### - eofの大文字小文字が 正しい | 逆
```bash
	<<EOF
	EOF
	eof
```
#### - 入力値が eofうち 1文字のみ | 1文字だけ正しい | 1文字違い
```bash
	cat <<EOF
	E
	eOf
	EoF

	EOF
```
#### - 複数のヒアドクで eofが全て異なる | 1つだけ異なる| 全て同じ
```bash
	cat <<EOF <<EOF2 <<EOF3
	1
	EOF
	2
	EOF2
	3
	EOF3
```
```bash
	cat <<EOF <<EOF2 <<EOF3
	1
	EOF
	2
	EOF
	3
	EOF3
```
```bash
	cat <<EOF <<EOF <<EOF2
	1
	EOF
	2
	EOF
	3
	EOF3
```
```bash
	cat <<EOF <<EOF <<EOF
	1
	EOF
	2
	EOF
	3
	EOF
```
#### - ヒアドクの 前に | 中間に | 後ろに cat
```bash
	cat <<EOF <<EOF
	1
	EOF
	2
	EOF
```
```bash
	<<EOF cat <<EOF
	1
	EOF
	2
	EOF
```
```bash
	<<EOF <<EOF cat
	1
	EOF
	2
	EOF
```

# 大きいテストケース
## file name length MAX (255)
<_000000010_000000020_000000030_000000040_000000050_000000060_000000070_000000080_000000090_000000100_000000110_000000120_000000130_000000140_000000150_000000160_000000170_000000180_000000190_000000200_000000210_000000220_000000230_000000240_000000250_0255


## file name length MAX + 1 (256)
<_000000010_000000020_000000030_000000040_000000050_000000060_000000070_000000080_000000090_000000100_000000110_000000120_000000130_000000140_000000150_000000160_000000170_000000180_000000190_000000200_000000210_000000220_000000230_000000240_000000250_00256

## path name length MAX (1023)
</000000010/000000020/000000030/000000040/000000050/000000060/000000070/000000080/000000090/000000100/000000110/000000120/000000130/000000140/000000150/000000160/000000170/000000180/000000190/000000200/000000210/000000220/000000230/000000240/000000250/000000260/000000270/000000280/000000290/000000300/000000310/000000320/000000330/000000340/000000350/000000360/000000370/000000380/000000390/000000400/000000410/000000420/000000430/000000440/000000450/000000460/000000470/000000480/000000490/000000500/000000510/000000520/000000530/000000540/000000550/000000560/000000570/000000580/000000590/000000600/000000610/000000620/000000630/000000640/000000650/000000660/000000670/000000680/000000690/000000700/000000710/000000720/000000730/000000740/000000750/000000760/000000770/000000780/000000790/000000800/000000810/000000820/000000830/000000840/000000850/000000860/000000870/000000880/000000890/000000900/000000910/000000920/000000930/000000940/000000950/000000960/000000970/000000980/000000990/000001000/000001010/000001020/23

## path name length MAX + 1 (1024)
</000000010/000000020/000000030/000000040/000000050/000000060/000000070/000000080/000000090/000000100/000000110/000000120/000000130/000000140/000000150/000000160/000000170/000000180/000000190/000000200/000000210/000000220/000000230/000000240/000000250/000000260/000000270/000000280/000000290/000000300/000000310/000000320/000000330/000000340/000000350/000000360/000000370/000000380/000000390/000000400/000000410/000000420/000000430/000000440/000000450/000000460/000000470/000000480/000000490/000000500/000000510/000000520/000000530/000000540/000000550/000000560/000000570/000000580/000000590/000000600/000000610/000000620/000000630/000000640/000000650/000000660/000000670/000000680/000000690/000000700/000000710/000000720/000000730/000000740/000000750/000000760/000000770/000000780/000000790/000000800/000000810/000000820/000000830/000000840/000000850/000000860/000000870/000000880/000000890/000000900/000000910/000000920/000000930/000000940/000000950/000000960/000000970/000000980/000000990/000001000/000001010/000001020/024
