# chudfetch
![chudfetch](images/chudfetch.png)

## requirements

- **linux-based operating system**
- **python 3.6+**
- **psutil**
- **utf-8 terminal**
- **git**

runtime data sources:

| field | source |
|---|---|
| user | `getpass.getuser()` |
| hostname | `platform.node()` |
| kernel | `platform.release()` |
| cpu | `platform.processor()` |
| ram | `psutil.virtual_memory()` |
| disk | `shutil.disk_usage("/")` |
| processes | `len(psutil.pids())` |
| shell | `$SHELL` |
| arch | `platform.machine()` |
| ip | UDP socket to `8.8.8.8:80` |
| date | `datetime.now()` |

## installation

### 1. get the code

```bash
git clone https://github.com/Efesint/chudfetch.git
cd chudfetch
```

### 2. install psutil

```bash
# debian
sudo apt install python3-psutil

# arch / manjaro
sudo pacman -S python-psutil
```

or with pip:

```bash
python3 -m pip install --user psutil
```

### 3. install the script into `~/.local/bin`

```bash
mkdir -p ~/.local/bin
install -m 755 src/chudfetch.py ~/.local/bin/chudfetch
```

### 4. run it

```bash
chudfetch
```

# DISCLAIMER / TERMS OF USE

**Please read this section in full before using, running, building, copying, forking, or otherwise interacting with this project in any way.**

## 1. Purpose of the Project

This project (hereinafter — "the Project", "the Program", "the Code") was created **strictly for entertainment, satirical, and educational purposes**. It is a joke, an artistic provocation, or a proof-of-concept demonstration, and is **not intended for any real-world practical use**.

The Project is **not**:
- a working tool;
- a means of circumventing lawful restrictions;
- a means of violating the laws of any jurisdiction;
- a means of causing harm;
- a means of gaining unauthorized access;
- a finished software product.

The author **makes no claims** regarding any usefulness, functionality, safety, or fitness of the Project for any purpose whatsoever.

## 2. No Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, ACCURACY, SAFETY, NON-INFRINGEMENT, AND FREEDOM FROM ERRORS.

The author **does not guarantee** that:
- the Code will work;
- the Code will work correctly;
- the Code will work safely;
- the Code will work in your environment;
- the Code will run at all;
- the Code is free of bugs, vulnerabilities, malicious or unwanted behavior;
- the Code complies with the laws of your jurisdiction;
- using the Code will not lead to negative consequences.

## 3. Limitation of Liability

THE AUTHOR **SHALL NOT BE LIABLE** for any direct, indirect, incidental, special, punitive, or consequential damages arising from the use, inability to use, misuse, build, distribution, or any other interaction with the Project, including but not limited to:

- loss or corruption of data;
- damage to hardware, software, or infrastructure;
- bricking of devices;
- leakage of confidential information;
- disruption of networks, servers, or services;
- financial loss, lost profits;
- termination of employment, disciplinary action, breach of contract;
- relationship breakdowns, family conflicts, and personal drama;
- reputational damage;
- legal consequences, claims, lawsuits, fines, administrative or criminal liability;
- global thermonuclear war, end of the world, apocalypse, or any other catastrophic event.

## 4. User Responsibility

By using, running, building, copying, forking, or otherwise interacting with the Project, you **acknowledge and agree** that:

1. You do so **entirely at your own risk**.
2. **You are solely responsible** for your actions and their consequences.
3. You will **comply with all applicable laws** of your jurisdiction.
4. You will **not hold the author liable** for any outcome.
5. You understand that the Project is a **joke** and does not represent a serious product.
6. You will **not use the Project** for any illegal, harmful, or malicious purpose.
7. If you do not agree with these terms, you **must not use** the Project.

## 5. No Maintenance or Support

The author **does not maintain, support, update, or guarantee** that this code will work in any environment. The Project may be abandoned, broken, incomplete, or non-functional at any time, with or without notice. Issues, pull requests, and questions may be ignored.

## 6. Third-Party Components

The Project may reference or depend on third-party software, services, or resources. The author **is not responsible** for the behavior, legality, availability, or safety of any third-party components. Their use is governed by their respective licenses and terms.

## 7. Severability

If any provision of this disclaimer is found to be invalid or unenforceable under applicable law, the remaining provisions shall remain in full force and effect.

## 8. Acceptance

**By using this Project in any way, you confirm that you have read, understood, and agreed to all of the above.**

**If you do not agree — do not use this Project.**

---

*Seriously. Use at your own risk.*
# LICENSE 
This product is released under the GNU General Public License v3.0
<br> see in LICENSE...
