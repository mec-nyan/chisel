// Chisel
//
// A simple code formatting tool.
//
// by Nano

fn main() {
    println!("Hello, world!");
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
}
