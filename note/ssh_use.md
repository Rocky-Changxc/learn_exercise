ssh免密登录

在authorized_keys配置好密钥后，若还不能免密登录，还需设置权限

```
chmod g-w /home/changxc
chmod 700 /home/changxc/.ssh
chmod 600 /home/changxc/.ssh/authorized_keys
```
