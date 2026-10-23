// Chisel
//
// A simple code formatting tool.
//
// by Nano

use std::collections::HashSet;

fn main() {
    let code = "local a = 41";

    // A simple example/test.  This is not the actual program!
    // We'll create token references and with that we're going to make the output string, by
    // applying the formatting rules.

    let mut in_id = false;
    let mut token = String::new();

    for c in code.chars() {
        if !in_id && names_can_begin_with(c) {
            token.clear();
            token.push(c);
            in_id = true;
            continue;
        }

        if in_id && names_can_contain(c) {
            token.push(c);
            continue;
        }

        if in_id && !names_can_contain(c) {
            in_id = false;
            break;
        }
    }

    if token.len() == 0 {
        eprintln!("No tokens found!");
    }

    if is_a_name(&token) {
        println!("'{}' is a valid name.", &token);
        if is_a_keyword(&token) {
            println!("\tAnd a keyword!");
        }
    }
}

fn names_can_begin_with(c: char) -> bool {
    c.is_ascii_alphabetic() || c == '_'
}

fn names_can_contain(c: char) -> bool {
    c.is_ascii_alphanumeric() || c == '_'
}

fn is_a_name(s: &str) -> bool {
    if s.len() == 0 {
        return false;
    }

    if !names_can_begin_with(s.chars().nth(0).unwrap()) {
        return false;
    }

    for c in s.chars() {
        if !names_can_contain(c) {
            return false;
        }
    }

    true
}

fn is_a_keyword(s: &str) -> bool {
    // TODO: Keywords (and so rules) should be passed as arguments for flexibility.
    // Anyway, now I'm just focusing on Lua code.
    let lua_keywords = HashSet::from([
        "and", "break", "do", "else", "elseif", "end", "for", "false", "function", "if", "in",
        "local", "nil", "not", "or", "repeat", "return", "then", "true", "until", "while",
    ]);

    lua_keywords.contains(s)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_names_begin_with() {
        for c in char::MIN..=char::MAX {
            match c {
                '_' | 'a'..='z' | 'A'..='Z' => assert!(names_can_begin_with(c)),
                _ => assert!(!names_can_begin_with(c)),
            }
        }
    }

    #[test]
    fn test_names_can_contain() {
        for c in char::MIN..=char::MAX {
            match c {
                '_' | 'a'..='z' | 'A'..='Z' | '0'..='9' => assert!(names_can_contain(c)),
                _ => assert!(!names_can_contain(c)),
            }
        }
    }

    #[test]
    fn test_is_a_name() {
        let valid_names = vec!["my_var", "_a_name", "x2", "cpp_rules", "rust_2"];

        for s in valid_names {
            assert!(is_a_name(s));
        }

        let invalid_names = vec!["my var", "_a name", "x+2", "12abc", "$name"];

        for s in invalid_names {
            assert!(!is_a_name(s));
        }
    }

    #[test]
    fn test_is_a_keyword() {
        let keywords = vec![
            "and", "break", "do", "else", "elseif", "end", "for", "false", "function", "if", "in",
            "local", "nil", "not", "or", "repeat", "return", "then", "true", "until", "while",
        ];

        for s in keywords {
            assert!(is_a_keyword(s));
        }

        let not_keywords = vec![
            "And",
            "AND",
            "Or",
            "END",
            "enter",
            "fuck it!",
            "keyword",
            "vector",
            "set",
            "let",
            "var",
            "def",
            "setq",
            "日本語",
            "アニメ",
            "fn",
            "fun",
            "func",
            "struct",
            "class",
            "continue",
        ];

        for s in not_keywords {
            assert!(!is_a_keyword(s));
        }
    }
}
